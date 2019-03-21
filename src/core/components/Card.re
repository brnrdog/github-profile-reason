let component = ReasonReact.statelessComponent("Card");

module Styles = {
  open Css;

  let card =
    style([
      border(px(1), `solid, hex("ebebeb")),
      borderRadius(rem(0.25)),
      padding(rem(1.0)),
    ]);
};

let make = (~className, children) => {
  ...component,
  render: _self =>
    <div className={Styles.card ++ " " ++ className}>
      {ReasonReact.array(children)}
    </div>,
};