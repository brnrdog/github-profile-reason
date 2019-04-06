module GetGitHubProfile = [%graphql
  {|
  query GitHubProfile {
    user(login: "gaearon") {
      id
      avatarUrl
    	bio
      company
      location
      name
      login
      websiteUrl

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

let mapEdges = edges =>
  Belt.Option.getWithDefault(edges, [||])
  |> Array.map(edge => Belt.Option.getExn(edge)##node);

module GitHubProfileQuery = ReasonApollo.CreateQuery(GetGitHubProfile);

let component = ReasonReact.statelessComponent("PinnedRepositoriesContainer");

let make = _children => {
  ...component,
  render: _self =>
    <GitHubProfileQuery>
      ...{({result}) =>
        switch (result) {
        | Loading => ReasonReact.string("Loading...")
        | Error(error) => ReasonReact.string(error##message)
        | Data(data) =>
          let user = Belt.Option.getExn(data##user);
          let repositories = mapEdges(user##repositories##edges);
          let pinnedRepositories = mapEdges(user##pinnedRepositories##edges);

          <>
            <Profile user />
            <PinnedRepositories repositories=pinnedRepositories />
            <RepositoriesList repositories />
          </>;
        }
      }
    </GitHubProfileQuery>,
};