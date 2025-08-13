package com.example.demo;

import java.util.Map;

import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api")
public class API_RequestManager {

    private final OneVOneCodingApplication oneVOneCodingApplication;

    API_RequestManager(OneVOneCodingApplication oneVOneCodingApplication) {
        this.oneVOneCodingApplication = oneVOneCodingApplication;
    }
	
    @PostMapping("/login")
    public boolean login(@RequestBody Map<String, String> login) {
        return DAO_Manager.checkUser(login.get("email"),login.get("password"));
    }
}



