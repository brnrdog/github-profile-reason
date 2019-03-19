let component = ReasonReact.statelessComponent("Sheet");

let style =
  ReactDOMRe.Style.make(
    ~background="#fff",
    ~borderRadius=".25rem",
    ~padding="1rem",
    ~boxShadow="0 2px 1px #eee",
    (),
  );

let make = children => {
  ...component,
  render: _self => <div style> {ReasonReact.array(children)} </div>,
};