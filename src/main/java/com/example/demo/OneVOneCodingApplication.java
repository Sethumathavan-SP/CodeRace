package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@SpringBootApplication
@Controller
public class OneVOneCodingApplication {
	public static void main(String[] args) {
		SpringApplication.run(OneVOneCodingApplication.class, args);
	}
	@GetMapping("/home.html")
	public String home() {
		return "home";
	}
	@GetMapping("/match.html")
	public String match() {
		return "match";
	}
	@GetMapping("/signin.html")
	public String signIn() {
		return "signin";
	}
	@GetMapping("/signup.html")
	public String signUp() {
		return "signup";
	}	
}
