open SheetStyles;
let component = ReasonReact.statelessComponent("Sheet");

let make = children => {
  ...component,
  render: _self => <div className=Styles.sheet> ...children </div>,
};