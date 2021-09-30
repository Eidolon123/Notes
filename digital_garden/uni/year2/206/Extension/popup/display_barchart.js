document.addEventListener('DOMContentLoaded', function()
{
    var ctx = document.getElementById("barchart").getContext('2d');
    var myChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: [ 'I', 'Hate', 'Chrome', 'Extensions' ],
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