module Styles = {
  open Css;
  open Theme;

  let wrapper =
    style([
      display(`flex),
      flexDirection(`column),
      marginBottom(em(4.0)),
      alignItems(`center),
      textAlign(`center),
      media(Breakpoints.small, [flexDirection(`row), textAlign(`left)]),
    ]);

  let avatar =
    style([height(em(7.0)), borderRadius(em(0.25)), margin(em(1.0))]);

  let title =
    style([fontSize(em(1.70)), lineHeight(em(1.5)), fontWeight(`light)]);

  let description = style([fontSize(em(1.0))]);

  let meta =
    style([
      display(`flex),
      alignItems(`center),
      color(hex("6B7687")),
      fontSize(em(0.875)),
      marginTop(em(0.5)),
      justifyContent(`center),
      media(
        Breakpoints.small,
        [
          flexDirection(`row),
          textAlign(`left),
          justifyContent(`flexStart),
        ],
      ),
    ]);

  let link = style([fontSize(em(0.85)), color(hex("74A7EE"))]);

  let icon =
    style([
      margin2(~v=px(0), ~h=em(0.5)),
      firstChild([marginLeft(px(0))]),
    ]);
};