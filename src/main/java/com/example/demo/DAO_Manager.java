package com.example.demo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Map;

public class DAO_Manager 
{
    private static final String URL = "jdbc:mysql://localhost:3306/codeClash";
    private static final String USER = "root";
    private static final String PASS = "1234";

    static 
    {
        try 
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } 
        catch (Exception e) 
        {
            throw new RuntimeException("Driver loading failed", e);
        }
    }

    public static Connection getConnection() throws SQLException 
    {
        return DriverManager.getConnection(URL, USER, PASS);
    }

    public static boolean checkUser(String email, String password) 
    {
        boolean found = false;
        String sql = "SELECT * FROM Users WHERE email = ? AND password = ?";
        try (Connection conn = getConnection();
             PreparedStatement ps = conn.prepareStatement(sql)) 
        {
            ps.setString(1, email);
            ps.setString(2, password);

            try (ResultSet rs = ps.executeQuery()) 
            {
                if (rs.next()) 
                {
                    found = true;
                }
            }
        } 
        catch (SQLException e) 
        {
            e.printStackTrace();
        }
        return found;
    }

	public static boolean signUp(Map<String, String> signup) {
		String name = signup.get("name");
		String email = signup.get("email");
		String password = signup.get("password");
		
		if(checkUser(email,password)) {
			return false;
		}
		
		String sql = "INSERT into users(username,email,password) values(?,?,?)";
		
		try(Connection conn = getConnection();
			PreparedStatement ps = conn.prepareStatement(sql))
		{
			ps.setString(1, name);
			ps.setString(2, email);
			ps.setString(3, password);
			
			ps.executeUpdate();
			
			return true;
		}
		catch(SQLException e) 
		{
			e.printStackTrace();
			return false;
		}
	}
}