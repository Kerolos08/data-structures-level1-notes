# Union

## What is Union?

In C++, a union is a user-defined data type that allows you to use the same memory location for different types of data.

The main reason to use a union is to save memory.

## Example:

```cpp
union MyUnion
{
int intValue;
float floatValue;
char charValue;
};
```

Note: the size of a union is determined by the size of its largest member.

Unlike structures, where each member has its own memory space, members of a union share the same memory space.

## Be careful:

Keep in mind that unions have some limitations and should be used with caution because they can lead to undefined behavior if not used properly.

When one member of the union is accessed, you should be careful about which member was last assigned a value.

## Union vs Struct

| Feature | `struct` | `union` |
| --- | --- | --- |
| Memory | Separate memory for each member | Shared memory |
| Can store all values at once? | Yes | No |
| Size | Sum of all members | Size of largest member |