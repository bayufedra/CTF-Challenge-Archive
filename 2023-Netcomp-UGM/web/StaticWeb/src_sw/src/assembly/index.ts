
function navbar(): string {
  return `
  <nav class="navbar is-primary" role="navigation" aria-label="main navigation">
  <div class="navbar-brand">
    <a class="navbar-item" href="#">
      <img src="logo.png" alt="Logo">
    </a>
    <button class="navbar-burger burger" aria-label="menu" aria-expanded="false" data-target="navbarMenu">
      <span aria-hidden="true"></span>
      <span aria-hidden="true"></span>
      <span aria-hidden="true"></span>
    </button>
  </div>
  <div class="navbar-menu" id="navbarMenu">
    <div class="navbar-start">
      <a class="navbar-item" href="#">Home</a>
      <a class="navbar-item" href="#about">About</a>
      <a class="navbar-item" href="#contact">Contact</a>
    </div>
  </div>
</nav>
  `
}

function home(): string {
  return `
<section class="hero is-fullheight">
  <div class="hero-body">
    <div class="container has-text-centered">
      <h1 class="title is-size-1">Welcome to the Home Page!</h1>
    </div>
  </div>
</section>
  `
}

function about(): string {
  return `
<section id="about" class="section">
  <div class="container">
    <div class="columns is-vcentered">
      <div class="column">
        <h2 class="title">About Us</h2>
        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam euismod ex id erat sagittis eleifend. Aenean pulvinar, sem id aliquam accumsan, justo nunc semper massa, non pellentesque urna justo sit amet lectus.</p>
      </div>
      <div class="column">
        <figure class="image">
          <img src="about-image.jpg" alt="About Us Image">
        </figure>
      </div>
    </div>
  </div>
</section>
  `
}

function contact(): string {
  return `
<section id="contact" class="section">
  <div class="container">
    <h2 class="title">Contact Us</h2>
    <div class="columns is-multiline">
      <div class="column is-half">
        <div class="field">
          <label class="label">Name</label>
          <div class="control">
            <input class="input" type="text" placeholder="Your Name">
          </div>
        </div>
        <div class="field">
          <label class="label">Email</label>
          <div class="control">
            <input class="input" type="email" placeholder="Your Email">
          </div>
        </div>
      </div>
      <div class="column is-half">
        <div class="field">
          <label class="label">Message</label>
          <div class="control">
            <textarea class="textarea" placeholder="Your Message"></textarea>
          </div>
        </div>
      </div>
      <div class="column is-full">
        <div class="field">
          <div class="control">
            <button class="button is-primary" type="submit">Submit</button>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
  `
}

export function index(urlHash: string): string {
  urlHash = decodeURI(urlHash)
  let output = navbar();

  if (urlHash === "") {
    output += home();
  } else if (urlHash === "about") {
    output += about();
  } else if (urlHash === "contact") {
    output += contact();
  } else {
    if (urlHash.startsWith("!")) {
      let pointer = urlHash.substring(1, urlHash.length)
      let pointer_int = usize(parseInt(pointer))
      let data = load<string>(pointer_int)
      output +=  data
    } else {
      output += "<h1>Page Not Found</h1>";
    }
  }
  return output;
}
