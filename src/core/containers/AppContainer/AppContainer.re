[@bs.module "react-spinners-kit"]
external spinner: ReasonReact.reactClass = "StageSpinner";

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

module GitHubProfileQuery = ReasonApollo.CreateQuery(GetGitHubProfile);

let component = ReasonReact.statelessComponent("PinnedRepositoriesContainer");

[@bs.deriving abstract]
type jsProps = {color: string};

let make = children => {
  ...component,
  render: _self =>
    <GitHubProfileQuery>
      ...{({result}) =>
        switch (result) {
        | Loading =>
          <div
            className={Css.style([
              Css.display(`flex),
              Css.justifyContent(`center),
            ])}>
            {ReasonReact.element(
               {ReasonReact.wrapJsForReason(
                  ~reactClass=spinner,
                  ~props=jsProps(~color="#847e7b"),
                  children,
                )},
             )}
          </div>
        | Error(error) => ReasonReact.string(error##message)
        | Data(data) =>
          open Graphql;
          let user = Belt.Option.getExn(data##user);
          let repositories = mapEdges(user##repositories##edges);
          let pinnedRepositories = mapEdges(user##pinnedRepositories##edges);

          <GitHubProfile user repositories pinnedRepositories />;
        }
      }
    </GitHubProfileQuery>,
};