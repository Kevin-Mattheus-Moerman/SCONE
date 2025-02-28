---
title: 'SCONE: Open Source Software for Predictive Simulation of Biological Motion'
authors:
- affiliation: 1
  name: Thomas Geijtenbeek
  orcid: 0000-0001-8352-8107
date: "19 April 2019"
bibliography: paper.bib
tags:
- predictive simulation
- neurobiomechanical modeling
- optimization
- data visualization
affiliations:
- index: 1
  name: Delft University of Technology, Delft, The Netherlands
---

# Summary
Mobility impairments pose an increasing burden on our ageing society, urging researchers and clinicians to invent new assistive technologies and improve medical treatment. However, their efforts are impeded by a gap in our understanding of biological motion. Even though individual branches of neuroscience and biomechanics have produced a wealth of knowledge of the components comprising biological motion, the fundamental question of how the neural, muscular and skeletal systems operate together to produce efficient and purposeful motion remains largely unanswered.

The use of neurological and musculoskeletal simulations can help improve our understanding of biological motion. Inverse dynamic simulations have been used successfully to estimate quantities of recorded human motion that are not directly observable, such as muscle force or joint torque. Even though these inverse simulations have provided useful insights into human motion, they rely on existing data and cannot predict new behavior.

Predictive forward dynamic simulations do the opposite: they compute motion trajectories that perform a given task optimally, according to high-level objectives such as stability, energy efficiency and pain avoidance. Predictive simulations enable powerful new applications for musculoskeletal models, such as predicting the outcome of treatment and optimizing the efficiency and efficacy of assistive devices. More fundamentally, it enables researchers to pose true *what-if?* questions, allowing them to investigate the effects of individual model and control parameters on the motion as a whole.

Despite having shown great promise [@Anderson2001, @Geijtenbeek2013], the number of studies that successfully employed predictive forward simulations has been remarkably limited. A main contributing factor is complexity: besides expertise in neurological and musculoskeletal modeling, users require knowledge and understanding of optimization theory, as well as advanced software development skills to tie these components together. Even successful projects often do not permit fruitful collaboration and follow-up research, due to lack of structure and documentation of the resulting code-base.

SCONE (Simulation-based Controller OptimizatioN Environment) is designed to help overcome these obstacles. It is a fully featured software framework that allows researchers to perform, analyze and reproduce custom predictive simulations of biological motion. SCONE features a user-friendly graphical user interface and can be used without programming skills.

SCONE is designed to cater to a wide range of potential users, including:
  * Clinical researchers with limited technical skills, who wish to perform *what-if* scenarios using existing SCONE Scenarios.
  * Biomechanics / neuromechanics researchers studying neuromuscular control.
  * Robotics researchers interested in optimized control strategies, or the interaction between humans and assistive devices.

Please visit https://scone.software for more information on SCONE, including tutorials, examples, documentation, community guidelines and contributions.

![The SCONE user interface](scone_window.png)

# Acknowledgements
The development of SCONE has been made possible through the following financial contributions:

  * The European Union’s Seventh Framework Programme for research, technological development and demonstration under grant agreement no 600932.
  * The National Center for Simulation in Rehabilitation Research (NIH P2C HD065690).
  * The VENI research program with project number 15153, which is (partly) financed by the Netherlands Organisation for Scientific Research (NWO).

# References
