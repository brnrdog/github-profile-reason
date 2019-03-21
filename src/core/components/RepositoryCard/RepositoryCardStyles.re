module Styles = {
  open Css;
  let card =
    style([
      minHeight(em(12.0)),
      display(`flex),
      flexDirection(`column),
      hover([background(hex("F8F8F8"))]),
      cursor(`pointer),
    ]);

  let title = style([fontSize(em(1.2)), marginBottom(em(1.0))]);

  let description =
    style([
      fontSize(em(1.0)),
      color(hex("354759")),
      lineHeight(em(1.5)),
    ]);

  let metaList =
    style([
      marginTop(`auto),
      fontSize(em(0.8)),
      color(hex("6B7687")),
      display(`flex),
      alignItems(`center),
    ]);

  let language =
    style([
      width(em(0.8)),
      height(em(0.8)),
      background(hex("F7CD4F")),
      borderRadius(`percent(50.0)),
      marginRight(em(0.5)),
    ]);

  let meta =
    style([display(`flex), marginRight(em(2.0)), alignItems(`center)]);

  let metaIcon = style([marginRight(em(0.5))]);
};