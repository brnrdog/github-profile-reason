open AppStyles;
let component = ReasonReact.statelessComponent("App");

let repository: RepositoryCard.repository = {
  id: "1",
  name: "Spawnpoint",
  description: "A starter template for new Rails projects",
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.app>
      <div className=Styles.container>
        <Sheet> <Profile /> <PinnedRepositories /> </Sheet>
      </div>
    </div>,
};