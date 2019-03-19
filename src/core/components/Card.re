let component = ReasonReact.statelessComponent("Card");

let makeStyle = style => {
  let default =
    ReactDOMRe.Style.make(
      ~border="1px solid #EBEBEB",
      ~borderRadius=".25rem",
      ~padding="1rem",
      (),
    );

  ReactDOMRe.Style.combine(default, style);
};

let make = (~style, children) => {
  ...component,
  render: _self =>
    <div style={makeStyle(style)}> {ReasonReact.array(children)} </div>,
};