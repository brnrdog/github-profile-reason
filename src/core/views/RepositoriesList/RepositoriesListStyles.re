module Styles = {
  open Css;
  let heading =
    style([
      fontSize(em(1.25)),
      margin2(~h=em(-1.0), ~v=px(0)),
      marginTop(em(2.0)),
      padding(em(1.0)),
      borderBottom(px(1), `solid, hex("EBEBEB")),
    ]);

  let listItem =
    style([
      margin2(~h=em(-1.0), ~v=px(0)),
      padding(em(1.0)),
      borderBottom(px(1), `solid, hex("EBEBEB")),
      hover([background(hex("F8F8F8"))]),
      lastChild([borderColor(`transparent), paddingBottom(px(0))]),
    ]);

  let title = style([fontSize(em(1.2)), marginBottom(em(1.0))]);
};