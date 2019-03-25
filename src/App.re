open AppStyles;
let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <ReasonApollo.Provider client=Data.instance>
      <div className=Styles.app>
        <div className=Styles.container>
          <Sheet>
            <Profile />
            <PinnedRepositoriesContainer />
            <RepositoriesListContainer />
          </Sheet>
        </div>
      </div>
    </ReasonApollo.Provider>,
};