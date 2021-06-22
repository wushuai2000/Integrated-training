<?php

 
require 'conn.php';
header('Content-Type:text/html;charset=utf-8');
error_reporting(E_ALL^E_NOTICE^E_WARNING);

//过滤表
function lib_replace_end_tag($str) {
    if (empty($str)) return false;
    $str = htmlspecialchars($str);
    $str = str_replace('/', "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace('(', "", $str);
    $str = str_replace(')', "", $str);
    $str = str_replace('CR', "", $str);
    $str = str_replace('ASCII', "", $str);
    $str = str_replace('ASCII 0x0d', "", $str);
    $str = str_replace('LF', "", $str);
    $str = str_replace('ASCII 0x0a', "", $str);
    $str = str_replace(',', "", $str);
    $str = str_replace('%', "", $str);
    $str = str_replace(';', "", $str);
    $str = str_replace('eval', "", $str);
    $str = str_replace('open', "", $str);
    $str = str_replace('sysopen', "", $str);
    $str = str_replace('system', "", $str);
    $str = str_replace('$', "", $str);
    $str = str_replace("'", "", $str);
    $str = str_replace("'", "", $str);
    $str = str_replace('ASCII 0x08', "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace("", "", $str);
    $str = str_replace("&gt", "", $str);
    $str = str_replace("&lt", "", $str);
    $str = str_replace("<SCRIPT>", "", $str);
    $str = str_replace("</SCRIPT>", "", $str);
    $str = str_replace("<script>", "", $str);
    $str = str_replace("</script>", "", $str);
    $str = str_replace("select", "", $str);
    $str = str_replace("join", "", $str);
    $str = str_replace("union", "", $str);
    $str = str_replace("where", "", $str);
    $str = str_replace("insert", "", $str);
    $str = str_replace("delete", "", $str);
    $str = str_replace("update", "", $str);
    $str = str_replace("like", "", $str);
    $str = str_replace("drop", "", $str);
    $str = str_replace("DROP", "", $str);
    $str = str_replace("sleep", "", $str);
    $str = str_replace("create", "", $str);
    $str = str_replace("modify", "", $str);
    $str = str_replace("rename", "", $str);
    $str = str_replace("alter", "", $str);
    $str = str_replace("cas", "", $str);
    $str = str_replace("&", "", $str);
    $str = str_replace(">", "", $str);
    $str = str_replace("<", "", $str);
    $str = str_replace(" ", chr(32), $str);
    $str = str_replace(" ", chr(9), $str);
    $str = str_replace("    ", chr(9), $str);
    $str = str_replace("&", chr(34), $str);
    $str = str_replace("'", chr(39), $str);
    $str = str_replace("<br />", chr(13), $str);
    $str = str_replace("''", "'", $str);
    $str = str_replace("css", "'", $str);
    $str = str_replace("CSS", "'", $str);
    $str = str_replace("<!--", "", $str);
    $str = str_replace("convert", "", $str);
    $str = str_replace("md5", "", $str);
    $str = str_replace("passwd", "", $str);
    $str = str_replace("password", "", $str);
    $str = str_replace("../", "", $str);
    $str = str_replace("./", "", $str);
    $str = str_replace("Array", "", $str);
    $str = str_replace("or 1='1'", "", $str);
    $str = str_replace(";set|set&set;", "", $str);
    $str = str_replace("`set|set&set`", "", $str);
    $str = str_replace("--", "", $str);
    $str = str_replace("OR", "", $str);
    $str = str_replace('"', "", $str);
    $str = str_replace("*", "", $str);
    $str = str_replace("-", "", $str);
    $str = str_replace("+", "", $str);
    $str = str_replace("/", "", $str);
    $str = str_replace("=", "", $str);
    $str = str_replace("'/", "", $str);
    $str = str_replace("-- ", "", $str);
    $str = str_replace(" -- ", "", $str);
    $str = str_replace(" --", "", $str);
    $str = str_replace("(", "", $str);
    $str = str_replace(")", "", $str);
    $str = str_replace("{", "", $str);
    $str = str_replace("}", "", $str);
    $str = str_replace("-1", "", $str);
    //$str = str_replace(".", "", $str);
    $str = str_replace("response", "", $str);
    $str = str_replace("write", "", $str);
    $str = str_replace("|", "", $str);
    $str = str_replace("`", "", $str);
    $str = str_replace(";", "", $str);
    $str = str_replace("etc", "", $str);
    $str = str_replace("root", "", $str);
    $str = str_replace("//", "", $str);
    $str = str_replace("!=", "", $str);
    $str = str_replace("$", "", $str);
    $str = str_replace("&", "", $str);
    $str = str_replace("&&", "", $str);
    $str = str_replace("==", "", $str);
    $str = str_replace("#", "", $str);
    //$str = str_replace("@", "", $str);
    $str = str_replace("mailto:", "", $str);
    $str = str_replace("CHAR", "", $str);
    $str = str_replace("char", "", $str);
	return $str;	 
}



$action = $_GET['model'];
switch ($action) {
    //账号登录登录  1-->登陆成功         0-->登录失败
    case"1":
        $name = lib_replace_end_tag($_POST['name']);
        $passwd2 = lib_replace_end_tag($_POST['passwd']);
        $passwd = md5("$passwd2" );
        $sqluser = "select name,passwd,onlyID  from `user` where name='" . $name . "' and passwd='" . $passwd2 . "'";
        $queryuser = mysqli_query($conn, $sqluser);
        // echo $sqluser;
        $rowuser = mysqli_fetch_array($queryuser,MYSQLI_ASSOC);
        //确保获取数据正确，并且不为空
        if ($rowuser && is_array($rowuser) && !empty($rowuser)) {
            //密码和用户名有都正确
            if ($rowuser['name'] == $name && $rowuser['passwd'] == $passwd2) {
                
                //密码正确
                $result = array(
                    'status' => '1',
                    'onlyID' => $rowuser['onlyID']
                );
                echo "11";
                exit();
            } else {
                $result = array(
                    'status' => '3',
                );
                echo "10";
                exit();
            }
        } else {
            $result = array(
                'status' => '2',
            );
            echo "-11";
            exit();
        }
    
        // 插入账号密码
    case "2":
        $name = lib_replace_end_tag($_POST['name']);
        $passwd = $_POST['passwd'];
        $passwd2 =  md5("$passwd");
        // 查询注册用户名字是否已存在
        $sqlfind= "select *  from `user` where name='" . $name . "'";
        $res = mysqli_query($conn,$sqlfind);
        $row = mysqli_fetch_array($res,MYSQLI_ASSOC);
        if($row['name']!=$name && !empty($name) && !empty($passwd) ){
            $add_sql = "INSERT INTO `user`(`name`, `passwd`) VALUES ('" . $name . "', '" . $passwd . "')";
            // echo $add_sql;
            $result = mysqli_query($conn, $add_sql);
            if (!$result) {
                echo $result;
                echo "20";
                break;
            }
            echo "21";
        }
        else{
            echo "-21";
        }
    break;
    default:
    exit();
}
?>