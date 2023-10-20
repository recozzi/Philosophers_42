<h1>Philosophers</h1>
<h2>Overview</h2>
The goal of this project is to find a solution to "the dining philosophers" problem. "Philosophers" is a dynamic simulation of philosophers sitting at a round table, alternately thinking, eating, or sleeping. This simulation is a classic problem in concurrent programming and synchronization, requiring multithreading techniques and mutexes.
<h2>How To Use</h2>
<ol>
  <li>Clone the repository:</li>
  <pre><code>git clone https://github.com/recozzi/Philosophers_42.git</code></pre>
  <li>Move to the project's directory:</li>
  <pre><code>cd Philosophers</code></pre>
  <li>Compile the project with Makefile rule:</li>
  <pre><code>make</code></pre>
  <li>Now you are ready to use philo</li>
  <pre><code>./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]</code></pre>
 <ul>
  <li>number_of_philosophers: the number of philosophers and also the number of forks (you can test a maximum of 200 philos).</li>
  <li>time_to_die (in milliseconds): if a philosopher doesn’t start eating 'time_to_die' milliseconds after starting their last meal or the simulation, they die.</li>
  <li>time_to_eat (in milliseconds): the time it takes for a philosopher to eat. During that time, they will need to hold two forks.</li>
  <li>time_to_sleep (in milliseconds): the time a philosopher will spend sleeping.</li>
  <li>number_of_times_each_philosopher_must_eat (optional): if all philosophers eat at least 'number_of_times_each_philosopher_must_eat' times, the simulation stops. If not specified, the simulation stops when a philosopher dies.</li>
</ul>
<h2>Info</h2>
For more information about this project, please read the subject file <a href="https://github.com/recozzi/Philosophers_42/blob/main/en.subject.pdf">here</a>.
<h2>Licence</h2>
See <a href="https://github.com/recozzi/Philosophers_42/blob/main/LICENSE">License</a>.
