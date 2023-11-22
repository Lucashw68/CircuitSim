# Circuit Simulator

This is a basic electronic circuit simulator. It loads a circuit from a configuration file and allows you to simulate its operation.

## Usage

```
./circuitsim <file_name> [<input=value> ...]
```

## Circuits

Circuits are defined in a configuration file. The file is a list of components and their connections. Each component is defined on a separate line. The first word on the line is the component type, followed by the component name, followed by the component's inputs and outputs. The inputs and outputs are separated by a colon. The inputs are separated by commas. The outputs are separated by spaces.

Configuration files are located in the ./circuits directory

## Syntax

Declare your components into the 'chipsets' section...
.chipsets:

And link them within the 'links' section
.links:
