let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <Sheet>
        <Card style={ReactDOMRe.Style.make(~height="300px", ())}>
          <h1> {ReasonReact.string("Spawnpoint")} </h1>
          <p> {ReasonReact.string("Some description goes here...")} </p>
        </Card>
      </Sheet>
    </div>,
};