open RepositoriesListStyles;
let component = ReasonReact.statelessComponent("RepositoriesList");

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
    description: "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam sem massa, laoreet eget elit id, auctor pharetra neque.",
  },
];

let make = _children => {
  ...component,
  render: _self => {
    let renderRepository = (repository: RepositoryCard.repository) => {
      <li className=Styles.listItem key={repository.id}>
        <div className=Styles.title>
          {ReasonReact.string(repository.name)}
        </div>
        <p> {ReasonReact.string(repository.description)} </p>
      </li>;
    };

    <>
      <div className=Styles.heading>
        {ReasonReact.string("Repositories")}
      </div>
      <ul>
        {repositories
         |> List.map(renderRepository)
         |> Array.of_list
         |> ReasonReact.array}
      </ul>
    </>;
  },
};