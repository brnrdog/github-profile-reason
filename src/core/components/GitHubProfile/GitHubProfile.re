let component = ReasonReact.statelessComponent("GitHubProfile");

let make = (~user, ~pinnedRepositories, ~repositories, _children) => {
  ...component,
  render: _self => {
    <Sheet>
      <Profile user />
      <PinnedRepositories repositories=pinnedRepositories />
      <RepositoriesList repositories />
    </Sheet>;
  },
};