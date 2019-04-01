[@bs.val] external githubApiToken: string = "process.env.GITHUB_API_TOKEN";

/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://api.github.com/graphql",
    ~headers=
      Js.Json.parseExn(
        "{\"Authorization\": \"Bearer " ++ githubApiToken ++ "\" }",
      ),
    (),
  );

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());