import "./app.css";
import ParticleBackground from "./ParticleBackground"

function App() {
  return (
    <div>
      <CenterTitle />
      <ParticleBackground />
    </div>
  );
}

function CenterTitle(){
  return(
    <div className="main">
      <div className="center">
        <div className="wrapper">
          <h1>ParticleJS</h1>
        </div>
      </div>
    </div>
  );
}

export default App;
