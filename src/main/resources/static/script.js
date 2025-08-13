console.log("Script loaded");
function goto(s) {
  window.location.href = s;
}
document.getElementById("login").addEventListener("click", () => {
  fetch("http://localhost:8080/api/login", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({
      email: document.getElementById("email").value,
      password: document.getElementById("password").value,
    }),
  })
    .then((res) => res.json())
    .then((result) => {
     	if(result){
			goto('/home.html');
		}
    })
    .catch((err) => console.error("Error:", err));
});
