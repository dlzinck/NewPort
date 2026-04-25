package com.snhu.sslserver;

import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

// Marks class as the main Spring Boot application
@SpringBootApplication
// Allows class to handle web requests directly
@RestController
public class SslServerApplication {
	// Starts Spring Boot application
	public static void main(String[] args) {
		SpringApplication.run(SslServerApplication.class, args);
	}
	// Creates route that returns the original data and its SHA-256 hash
	@GetMapping("/hash")
	public String showHash() throws NoSuchAlgorithmException {
		// Unique data string used for checksum verification
		String data = "Drew Zinck - CS 305 Project Two Checksum";
		// Creates a MessageDigest object using the SHA-256 hashing algorithm
		MessageDigest digest = MessageDigest.getInstance("SHA-256");
		// Converts original string into bytes and hashes it
		byte[] hashBytes = digest.digest(data.getBytes(StandardCharsets.UTF_8));
		// Builds hexadecimal version of hash output
		StringBuilder hexString = new StringBuilder();
		// Converts each byte into two-character hexadecimal value
		for (byte b : hashBytes) {
			hexString.append(String.format("%02x", b));
		}
		// Returns original data and checksum result to the browser
		return "Original Data: " + data + "<br><br>SHA-256 Hash: " + hexString.toString();
	}
}