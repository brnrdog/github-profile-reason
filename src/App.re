open AppStyles;
let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <ReasonApollo.Provider client=GitHubApolloClient.instance>
      <div className=Styles.app>
        <div className=Styles.container>
          <Sheet> <AppContainer /> </Sheet>
        </div>
      </div>
    </ReasonApollo.Provider>,
};