<?php

function download_via_url($url){

    $checkUrl = parse_url($url);

    if (!in_array($checkUrl["scheme"], ["http", "https"])){
        return false;
    }
    
    if (filter_var($url, FILTER_VALIDATE_URL) === false){
        return false;
    }

    $blacklisted = array('php', 'phtml', 'php3', 'php4', 'php5', 'phar');

    $ext = pathinfo(basename($url), PATHINFO_EXTENSION);
    if (in_array($ext, $blacklisted, true)) {
        return false;
    }

    if (!$checkUrl["path"]){
        return false;
    }

    $tempWorkdir = "./download/temp/".rand(100,1000);
    if (!file_exists($tempWorkdir)) {
        mkdir($tempWorkdir, 0777, true);
    }

    $tempFilename = $tempWorkdir."/".basename($url);
    $tempFile = fopen($tempFilename, 'w');

    $getUrl = fopen($url, 'r');
    
    $fileSize = 0;

    if ($tempFile && $getUrl) {
        while (!feof($getUrl)) {
            $chunk = fread($getUrl, 1024);
            $fileSize += strlen($chunk);

            if ($fileSize > 2048) {
                break;
            }

            fwrite($tempFile, $chunk);
        }

        fclose($tempFile);
        fclose($getUrl);

        $output = file_get_contents($tempFilename);
        unlink($tempFilename);
        return $output;
    }

    return false;
}

if ($_POST["url"]){
    $output = download_via_url($_POST["url"]);
    if ($output){
        header('Content-Description: File Transfer');
        header('Content-Type: application/octet-stream');
        header('Content-Disposition: attachment; filename='.basename($_POST["url"]));
        header('Expires: 0');
        header('Cache-Control: must-revalidate');
        header('Pragma: public');
        header('Content-Length: ' . strlen($output));

        echo $output;
    }
    else {
        header("Location: index.php");
    }
}