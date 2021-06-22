<?php
include("gec6818.php");
// age=60&appellation=1&city=长沙市&education=本科及以上&gender=男&height=170&idcard=4432353535345&name=赵小明&nation=汉族&openid=21312321&patient=患者&phone=12345678903&province=湖南省&waist=50&weight=70
$time_data = date('Y-m-d H:i:s');
if(isset($_POST['temp']) && isset($_POST['humidity']) && isset($_POST['beep']) && isset($_POST['relay']) && isset($_POST['reverse']) && isset($_POST['led1']) && isset($_POST['led2']) && isset($_POST['led3']) && isset($_POST['warn'])){
    $sql = "INSERT INTO `GEC6818`.`data`( `time`,`temp`,`humidity`,`beep`,`relay`,`reverse`,`led1`,`led2`,`led3`,`warn`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    $sth = $pdo->prepare($sql);
    $sth->bindParam(1, $time_data);
    $sth->bindParam(2,$_POST['temp']);
    $sth->bindParam(3,$_POST['humidity']);
    $sth->bindParam(4,$_POST['beep']);
    $sth->bindParam(5,$_POST['relay']);
    $sth->bindParam(6,$_POST['reverse']);
    $sth->bindParam(7,$_POST['led1']);
    $sth->bindParam(8,$_POST['led2']);
    $sth->bindParam(9,$_POST['led3']);
    $sth->bindParam(10,$_POST['warn']);
    if(!$sth->execute()){
        die("error");
    }
    $result = $sth->fetchAll();
    $sth->closeCursor();
    die("1");
}else{
    die("-1");
}

