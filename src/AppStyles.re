module Styles = {
  open Css;

  let app =
    style([
      background(hex("f7f5f4")),
      lineHeight(em(1.5)),
      fontFamily(
        "-apple-system, BlinkMacSystemFont, \"Segoe UI\", Roboto, Oxygen, Ubuntu, Cantarell, \"Open Sans\", \"Helvetica Neue\", sans-serif",
      ),
      minHeight(vh(100.0)),
      fontSize(px(14)),
      fontWeight(`lighter),
    ]);

  let container =
    style([
      maxWidth(px(1100)),
      margin2(~v=px(0), ~h=`auto),
      padding(em(2.0)),
    ]);
};