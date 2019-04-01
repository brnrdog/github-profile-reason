module GetUserProfile = [%graphql
  {|
  query UserProfile {
    user(login: "gaearon") {
    	id
      avatarUrl
    	bio
      company
      location
      name
      login
      websiteUrl
    }
  }
|}
];

type payload;

module PinnedRepositoriesQuery = ReasonApollo.CreateQuery(GetUserProfile);

let component = ReasonReact.statelessComponent("ProfileContainer");

let make = _children => {
  ...component,
  render: _self =>
    <PinnedRepositoriesQuery>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {ReasonReact.string("Loading...")} </div>
        | Error(error) => <div> {ReasonReact.string(error##message)} </div>
        | Data(data) =>
          switch (data##user) {
          | None => ReasonReact.string("Hello")
          | Some(user) => <Profile user />
          }
        }
      }
    </PinnedRepositoriesQuery>,
};