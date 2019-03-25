open PinnedRepositoriesStyles;
let component = ReasonReact.statelessComponent("PinnedRepositories");

let toRepositoryCard = someRepository => {
  let repository = Belt.Option.getExn(someRepository);
  <RepositoryCard
    key={
      repository##id;
    }
    className=Styles.card
    repository
  />;
};

let make = (~repositories, _children) => {
  ...component,
  render: _self =>
    <div>
      <h2 className=Styles.heading>
        {ReasonReact.string("Pinned Repositories")}
      </h2>
      <div className=Styles.list>
        {repositories |> Array.map(toRepositoryCard) |> ReasonReact.array}
      </div>
    </div>,
};