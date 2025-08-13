console.log("Script Loaded");

function goto(s) {
    window.location.href = s;
}

document.getElementById('login').addEventListener('click', () => {
    fetch("/api/login", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({
            email: document.getElementById("email").value,
            password: document.getElementById("password").value,
        }),
    })
    .then(res => res.json()) // parse response as JSON (true/false)
    .then(isValid => {
        if (isValid) {
            goto('/home'); 
        } else {
            alert("Invalid email or password");
        }
    })
    .catch(err => alert(err.message));
});
