open AppStyles;
let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <ReasonApollo.Provider client=GitHubApolloClient.instance>
      <div className=Styles.app>
        <div className=Styles.container> <AppContainer /> </div>
      </div>
    </ReasonApollo.Provider>,
};