module Styles = {
  open Css;

  let heading = style([fontSize(em(1.25)), marginBottom(em(1.0))]);

  let list = style([display(`flex), justifyContent(`spaceBetween)]);

  let card =
    style([
      width(`percent(100.0)),
      margin(em(1.0)),
      firstChild([marginLeft(px(0))]),
      lastChild([marginRight(px(0))]),
    ]);
};