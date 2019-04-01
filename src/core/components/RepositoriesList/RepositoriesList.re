open RepositoriesListStyles;
let component = ReasonReact.statelessComponent("RepositoriesList");

let make = (~repositories, _children) => {
  ...component,
  render: _self => {
    let renderRepository = someRepository => {
      let repository = Belt.Option.getExn(someRepository);
      <li
        className=Styles.listItem
        key={
          repository##id;
        }>
        <div className=Styles.title>
          {ReasonReact.string(repository##name)}
        </div>
        {switch (repository##description) {
         | None =>
           <p className=Styles.noDescription>
             {ReasonReact.string("No description given")}
           </p>
         | Some(description) =>
           <p className=Styles.description>
             {ReasonReact.string(description)}
           </p>
         }}
        <div className=Styles.metaList>
          {switch (repository##primaryLanguage) {
           | None => ReasonReact.null
           | Some(primaryLanguage) =>
             <div className=Styles.meta>
               <div
                 className={Styles.language(
                   primaryLanguage##color->Belt.Option.getWithDefault("#ccc"),
                 )}
               />
               {ReasonReact.string(primaryLanguage##name)}
             </div>
           }}
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
      </li>;
    };

    <>
      <div className=Styles.heading>
        {ReasonReact.string("Repositories")}
      </div>
      <ul>
        {repositories |> Array.map(renderRepository) |> ReasonReact.array}
      </ul>
    </>;
  },
};