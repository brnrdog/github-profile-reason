open PinnedRepositoriesStyles;
let component = ReasonReact.statelessComponent("PinnedRepositories");

let repositories: list(RepositoryCard.repository) = [
  {
    id: "1",
    name: "Spawnpoint",
    description: "A starter template for Rails projects",
  },
  {
    id: "2",
    name: "Spawnpoint",
    description: "A starter template for Rails projects",
  },
  {
    id: "3",
    name: "Spawnpoint",
    description: "A starter template for Rails projects",
  },
];

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h2 className=Styles.heading>
        {ReasonReact.string("Pinned Repositories")}
      </h2>
      <div className=Styles.list>
        {ReasonReact.array(
           Array.of_list(
             repositories
             |> List.map(repository =>
                  <RepositoryCard className=Styles.card repository />
                ),
           ),
         )}
      </div>
    </div>,
};