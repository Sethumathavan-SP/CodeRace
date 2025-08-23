console.log("Script Loaded");

function goto(s) {
    window.location.href = s;
}

document.addEventListener("DOMContentLoaded", () => {
	const loginBtn = document.getElementById('login');
	
	if (loginBtn) {
		loginBtn.addEventListener('click', () => {
		    fetch("/api/login", {
		        method: "POST",
		        headers: { "Content-Type": "application/json" },
		        body: JSON.stringify({
		            email: document.getElementById("email").value,
		            password: document.getElementById("password").value,
		        }),
		    })
		    .then(res => res.json())
		    .then(isValid => {
		        if (isValid) {
		            goto('/home'); 
		        } else {
		            alert("Invalid email or password");
		        }
		    })
		    .catch(err => alert(err.message));
		});
	}
	
	const signupBtn = document.getElementById('signup');
	console.log(signupBtn);
	if (signupBtn) {
		signupBtn.addEventListener('click',() => {
			fetch("api/signup",{
				method: "POST",
				headers: {"Content-Type" : "application/json" },
				body: JSON.stringify({
					email:document.getElementById("email").value,
					password:document.getElementsByName("Password")[0].value,
					name :document.getElementsByName("full-name")[0].value
				}),
			})
			.then(res => res.json())
			.then(isValid => {
				if(isValid){
					goto('/home');
				} else {
					alert("signup-failed");
				}
			})
			.catch(err => alert(err.message));
		});
	}
});