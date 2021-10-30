<?php
set_time_limit(0);
include("header.php");

$myFile = "input_url.txt";
$fh = fopen($myFile, 'w') or die("can't open file");
$stringData = $_POST['data'];
fwrite($fh, $stringData);

fclose($fh);
$python = `python phish_rf.py`;
echo "<h2>Random Forest Algorithm Result</h2>";
echo "<pre>".$python."</pre>";


$python1 = `python phish_svm.py`;
echo "<h2>SVM Algorithm Result</h2>";
echo "<pre>".$python1."</pre>";


$python2 = `python phish_knn.py`;
echo "<h2>KNN Algorithm Result</h2>";
echo "<pre>".$python2."</pre>";


?>
