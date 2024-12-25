<?php
// Establish database connection
$servername = "db";
$username = "root";
$password = "rootp@ssw0rd123";
$dbname = "tmpstorage";

$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
     die("Connection failed: " . $conn->connect_error);
}
