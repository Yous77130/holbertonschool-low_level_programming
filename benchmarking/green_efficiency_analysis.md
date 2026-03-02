# Green Efficiency Analysis: Benchmarking and Instrumentation

## Measurement Methodology
To evaluate the computational efficiency and potential energy impact of our algorithms, we employed two primary methods. First, we conducted a direct comparison between two mathematical approaches (`slow_calc.c` and `fast_calc.c`) using a high-precision timer script. Second, we implemented manual instrumentation in `instrumentation_lab.c` using the `<time.h>` library. The `clock()` function was used to capture processor cycles at the start and end of specific code blocks, which were then converted into seconds using the `CLOCKS_PER_SEC` macro. This allowed for a granular breakdown of the program's lifecycle: data building, processing, and reduction.

## Observed Performance Differences
The results from Task 1 showed a stark contrast in efficiency. The "Slow" algorithm, characterized by a nested loop structure $O(n^2)$, required significantly more time to process the dataset compared to the "Fast" algorithm, which utilized a more direct $O(1)$ or $O(n)$ approach. 

In my instrumentation lab, the breakdown was as follows:
- **BUILD_DATA**: [Insère ton temps ici, ex: 0.001245] seconds
- **PROCESS**: [Insère ton temps ici, ex: 0.008432] seconds
- **REDUCE**: [Insère ton temps ici, ex: 0.000954] seconds
- **TOTAL**: [Insère ton temps ici] seconds

The processing phase was consistently the most resource-intensive, consuming over [X]% of the total execution time. This confirms that optimization efforts should be prioritized on the processing logic rather than data initialization.

## Relation Between Runtime and Energy Consumption
While we did not measure power draw in Watts, runtime serves as a reliable proxy for energy consumption. Modern CPUs consume power in several ways, primarily through dynamic power dissipation during switching activities. A longer runtime means the CPU remains in a high-power C-state (active state) for an extended period. By reducing the execution time from the "Slow" algorithm's duration to the "Fast" version, we directly reduce the total number of clock cycles required. Fewer cycles lead to less heat dissipation and lower total energy (Joules) consumed by the hardware to complete the same logical task, aligning with Green IT principles.

## Limitations of the Experiment
There are several limitations to this study. First, `clock()` measures CPU time, not "wall-clock" time; it does not account for I/O wait times or system-level scheduling delays. Second, our environment is a shared sandbox, meaning background processes could introduce noise in the measurements. Most importantly, runtime is only a proxy; it doesn't account for memory power consumption or the energy cost of data movement between cache levels and RAM, which can be significant in larger datasets.

## Practical Engineering Takeaway
The primary takeaway is that "Green Coding" is fundamentally about algorithmic efficiency. As engineers, writing code that completes a task in $O(n)$ instead of $O(n^2)$ is the most impactful way to reduce the environmental footprint of software. Instrumentation is the essential first step in this process: we cannot optimize what we cannot measure. By identifying "hotspots" through timing, we can apply surgical optimizations that yield the highest return on investment for both performance and sustainability.# Green Efficiency Analysis: Benchmarking and Instrumentation

## Measurement Methodology
To evaluate the computational efficiency and potential energy impact of our algorithms, we employed two primary methods. First, we conducted a direct comparison between two mathematical approaches (`slow_calc.c` and `fast_calc.c`) using a high-precision timer script. Second, we implemented manual instrumentation in `instrumentation_lab.c` using the `<time.h>` library. The `clock()` function was used to capture processor cycles at the start and end of specific code blocks, which were then converted into seconds using the `CLOCKS_PER_SEC` macro. This allowed for a granular breakdown of the program's lifecycle: data building, processing, and reduction.

## Observed Performance Differences
The results from Task 1 showed a stark contrast in efficiency. The "Slow" algorithm, characterized by a nested loop structure $O(n^2)$, required significantly more time to process the dataset compared to the "Fast" algorithm, which utilized a more direct $O(1)$ or $O(n)$ approach. 

In my instrumentation lab, the breakdown was as follows:
- **BUILD_DATA**: [Insère ton temps ici, ex: 0.001245] seconds
- **PROCESS**: [Insère ton temps ici, ex: 0.008432] seconds
- **REDUCE**: [Insère ton temps ici, ex: 0.000954] seconds
- **TOTAL**: [Insère ton temps ici] seconds

The processing phase was consistently the most resource-intensive, consuming over [X]% of the total execution time. This confirms that optimization efforts should be prioritized on the processing logic rather than data initialization.

## Relation Between Runtime and Energy Consumption
While we did not measure power draw in Watts, runtime serves as a reliable proxy for energy consumption. Modern CPUs consume power in several ways, primarily through dynamic power dissipation during switching activities. A longer runtime means the CPU remains in a high-power C-state (active state) for an extended period. By reducing the execution time from the "Slow" algorithm's duration to the "Fast" version, we directly reduce the total number of clock cycles required. Fewer cycles lead to less heat dissipation and lower total energy (Joules) consumed by the hardware to complete the same logical task, aligning with Green IT principles.

## Limitations of the Experiment
There are several limitations to this study. First, `clock()` measures CPU time, not "wall-clock" time; it does not account for I/O wait times or system-level scheduling delays. Second, our environment is a shared sandbox, meaning background processes could introduce noise in the measurements. Most importantly, runtime is only a proxy; it doesn't account for memory power consumption or the energy cost of data movement between cache levels and RAM, which can be significant in larger datasets.

## Practical Engineering Takeaway
The primary takeaway is that "Green Coding" is fundamentally about algorithmic efficiency. As engineers, writing code that completes a task in $O(n)$ instead of $O(n^2)$ is the most impactful way to reduce the environmental footprint of software. Instrumentation is the essential first step in this process: we cannot optimize what we cannot measure. By identifying "hotspots" through timing, we can apply surgical optimizations that yield the highest return on investment for both performance and sustainability.
