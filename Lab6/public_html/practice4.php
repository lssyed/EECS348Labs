<!DOCTYPE html>
<html>
    <head>
        <title>Practice 4</title>
        <style>
            table, th, td{
                border: 1px solid black;
                padding: 8px;
                text-align: center;
            }
        </style>
    </head>
    <body>
        <?php
        $num = $_POST["number"];
        
        echo "<h2>Multiplication Table up to $num</h2>";

        echo "<table>";

        echo "<tr>";
        echo "<th> * </th>";

        for ($col = 1; $col <= $num; $col++) {
            echo "<th>" . $col . "</th>";
        }
        echo "</tr>";

        for ($row = 1; $row <= $num; $row++) {
            echo "<tr>";

            echo "<th>" . $row . "</th>";

            for ($col = 1; $col <= $num; $col++) {
                $answer = $row * $col;
                echo "<td>" . $answer . "</td>";
            }

            echo "</tr>";
        }

        echo "</table>";
        ?>
    </body> 
</html>