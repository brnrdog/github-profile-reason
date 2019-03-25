open RepositoryCardStyles;
let component = ReasonReact.statelessComponent("RepositoryCard");

let make = (~className, ~repository, _children) => {
  ...component,
  render: _self =>
    <Card className={Styles.card ++ " " ++ className}>
      <h1 className=Styles.title> {ReasonReact.string(repository##name)} </h1>
      <p className=Styles.description>
        {ReasonReact.string(
           Belt.Option.getWithDefault(repository##description, ""),
         )}
      </p>
      <div className=Styles.metaList>
        <div className=Styles.meta>
          <div className=Styles.language />
          {ReasonReact.string("JavaScript")}
        </div>
        <div className=Styles.meta>
          <svg
            className=Styles.metaIcon
            xmlns="http://www.w3.org/2000/svg"
            width="15"
            height="15"
            fill="#6B7687"
            viewBox="0 0 14 16">
            <path
              fillRule="evenodd"
              d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74L14 6z"
            />
          </svg>
          {ReasonReact.string(
             string_of_int(repository##stargazers##totalCount),
           )}
        </div>
        <div className=Styles.meta>
          <svg
            className=Styles.metaIcon
            xmlns="http://www.w3.org/2000/svg"
            width="15"
            height="15"
            fill="#6B7687"
            viewBox="0 0 10 16">
            <path
              fillRule="evenodd"
              d="M8 1a1.993 1.993 0 0 0-1 3.72V6L5 8 3 6V4.72A1.993 1.993 0 0 0 2 1a1.993 1.993 0 0 0-1 3.72V6.5l3 3v1.78A1.993 1.993 0 0 0 5 15a1.993 1.993 0 0 0 1-3.72V9.5l3-3V4.72A1.993 1.993 0 0 0 8 1zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3 10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3-10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"
            />
          </svg>
          {ReasonReact.string(string_of_int(repository##forkCount))}
        </div>
      </div>
    </Card>,
};