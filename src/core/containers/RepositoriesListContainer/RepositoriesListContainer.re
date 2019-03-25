module GetRepositories = [%graphql
  {|
    query Repositories {
      user(login: "gaearon") {
        repositories(first: 10) {
          edges {
            node {
              id
              name
              description
              forkCount

              stargazers {
                totalCount
              }

              primaryLanguage {
               color
                name
              }
            }
          }
        }
      }
    }
  |}
];

type payload;

module RepositoriesQuery = ReasonApollo.CreateQuery(GetRepositories);

let component = ReasonReact.statelessComponent("RepositoriesListContainer");

let getMaybeRepositories = data => {
  switch (data##user) {
  | None => [||]
  | Some(user) =>
    switch (user##repositories##edges) {
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
};

let make = _children => {
  ...component,
  render: _self =>
    <RepositoriesQuery>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {ReasonReact.string("Loading...")} </div>
        | Error(error) => <div> {ReasonReact.string(error##message)} </div>
        | Data(data) =>
          let repositories = getMaybeRepositories(data);
          <RepositoriesList repositories />;
        }
      }
    </RepositoriesQuery>,
};