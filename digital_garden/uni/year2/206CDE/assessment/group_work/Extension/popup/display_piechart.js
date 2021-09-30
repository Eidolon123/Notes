document.addEventListener('DOMContentLoaded', function()
{
    var ctx = document.getElementById("piechart").getContext('2d');
    var myChart = new Chart(ctx, {
        type: 'pie',
        data: {
            labels: [ 'SQL', 'XSS', 'SourceCode', 'Extensions' ],
                datasets: [{
                backgroundColor: [
                    "#59be5b",
                    "#d56328",
                    "#ff1b2d",
                    "#0078d7"
                ],
                data: [ 1, 2, 3, 4 ]
            }]
        }
    });
});