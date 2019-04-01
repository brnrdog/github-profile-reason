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

  let description = style([marginBottom(em(1.0)), color(hex("354759"))]);
  let noDescription =
    style([opacity(0.5), marginBottom(em(1.0)), color(hex("354759"))]);

  let metaList =
    style([
      marginTop(`auto),
      color(hex("6B7687")),
      display(`flex),
      alignItems(`center),
    ]);

  let language = color => {
    let hexColor = String.sub(color, 1, String.length(color) - 1);
    style([
      width(em(0.8)),
      height(em(0.8)),
      background(hex(hexColor)),
      borderRadius(`percent(50.0)),
      marginRight(em(0.5)),
    ]);
  };

  let meta =
    style([display(`flex), marginRight(em(2.0)), alignItems(`center)]);

  let metaIcon = style([marginRight(em(0.5))]);
};