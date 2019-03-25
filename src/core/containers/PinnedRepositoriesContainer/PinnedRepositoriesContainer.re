module GetPinnedRepositories = [%graphql
  {|
  query PinnedRepositories {
    user(login: "gaearon") {
      pinnedRepositories(first: 3) {
        edges {
          node {
            id
            name
            description
            forkCount
            
            primaryLanguage {
              color
              name
            }
            
            stargazers {
              totalCount
            }
          }
        }
      }
    }
  }
|}
];

type payload;

module PinnedRepositoriesQuery =
  ReasonApollo.CreateQuery(GetPinnedRepositories);

let component = ReasonReact.statelessComponent("PinnedRepositoriesContainer");

let make = _children => {
  ...component,
  render: _self =>
    <PinnedRepositoriesQuery>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {ReasonReact.string("Loading...")} </div>
        | Error(error) => <div> {ReasonReact.string(error##message)} </div>
        | Data(data) =>
          let repositories =
            switch (data##user) {
            | None => [||]
            | Some(user) =>
              switch (user##pinnedRepositories##edges) {
              | None => [||]
              | Some(edges) =>
                Array.map(
                  edge =>
                    switch (edge) {
                    | Some(edge) => edge##node
                    | None => None
                    },
                  edges,
                )
              }
            };
          <PinnedRepositories repositories />;
        }
      }
    </PinnedRepositoriesQuery>,
};