<?php

$servername = "47.100.56.86";
$username   = "user";
$password   = "123321";
$dbname     = "GEC6818";

// 创建连接
$conn = new mysqli($servername, $username, $password, $dbname);

// 检测连接
if ($conn->connect_error)
{
    die("连接失败: " . $conn->connect_error);
}

$sql = "UPDATE room_led SET sitting = '" . $_POST["sitting"] ."',kitchen = '".$_POST["kitchen"]."',bedroom = '".$_POST["bedroom"]."', toilet = '".$_POST["toilet"]."' WHERE id = 1";

mysqli_query($conn,$sql);
mysqli_close($conn);