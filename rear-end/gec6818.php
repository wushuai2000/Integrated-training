<?php
$servername = "47.100.56.86";
$username = "user";
$password = "123321";
$dbname = "GEC6818";
error_reporting(0);
header("content-type:text/html;charset=utf-8");
$pdo = new PDO("mysql:host=".$servername.";dbname=".$dbname.";charset=utf8",$username, $password);
if (!$pdo) {
    die("Connection failed: " . mysqli_connect_error());
}
$pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);