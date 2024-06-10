<h1>so_long</h1>

<h2>Introduction</h2>
<p>Welcome to the <strong>so_long</strong> project, an exciting part of the 42 curriculum. This project focuses on creating a simple 2D game using the MiniLibX library, which involves rendering graphics, handling user input, and managing game logic.</p>

<h2>Objective</h2>
<p>The objective of the "so_long" project is to develop a small game where a player navigates through a map, collecting items and reaching an exit. The project emphasizes working with 2D graphics, managing game states, and handling events such as keyboard inputs.</p>

<h2>Requirements</h2>
<p>The game must meet the following requirements:</p>
<ul>
    <li>Display a window with the game's graphical content using MiniLibX.</li>
    <li>Render a player character that can move around the map.</li>
    <li>Include collectible items that the player can pick up.</li>
    <li>Provide an exit point that the player can reach to win the game.</li>
    <li>Ensure the game window can be closed by a key press or clicking the close button.</li>
</ul>

<h2>Key Concepts</h2>
<ul>
    <li><strong>MiniLibX</strong>: A simple X-Window (X11) programming interface for creating graphical applications.</li>
    <li><strong>2D Graphics</strong>: Techniques for rendering images, sprites, and game elements on a 2D plane.</li>
    <li><strong>Event Handling</strong>: Managing user inputs such as keyboard and mouse events to control the game.</li>
    <li><strong>Game Logic</strong>: Implementing the rules and mechanics that define the game's behavior.</li>
</ul>

<h2>Example of Usage</h2>
<p>Here's a basic example of how you might begin implementing the <code>so_long</code> project:</p>
<pre><code>#include &lt;mlx.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct  s_data {
void        *mlx;
void        *win;
void        *img;
int         img_width;
int         img_height;
}               t_data;

int close_window(t_data *data)
{
mlx_destroy_window(data->mlx, data->win);
exit(0);
}

int main(void)
{
t_data  data;

data.mlx = mlx_init();
if (data.mlx == NULL)
    return (1);
data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
if (data.win == NULL)
{
    free(data.mlx);
    return (1);
}
mlx_hook(data.win, 17, 0, close_window, &data);
mlx_loop(data.mlx);
return (0);
}
</code></pre>
 <h2>Image Preview</h2>
    <p>Below is an image preview of the game in action:</p>
    <img src="so_long.png.png" alt="so_long game preview">
<h2>Video Overview</h2>
<p><strong>so_long</strong> project:</p>
<video width="560" height="315" controls>
    <source src="so_long.mov" type="video/mov">
</video>
<h2>Conclusion</h2>
<p>The <strong>so_long</strong> project is an excellent opportunity to delve into game development and graphical programming. By completing this project, you will gain valuable skills in rendering 2D graphics, handling user input, and managing game states, all of which are essential for creating interactive applications.</p>
<p>Feel free to explore, experiment, and enhance your implementation to make your game even more engaging!</p>
