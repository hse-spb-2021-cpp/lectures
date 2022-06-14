// Destructors cannot be SFINAEd out. C++20: concepts to the rescue!
// Having a destructor makes the difference between TriviallyDestructible types and others.

~Foo() noexcept(?????) {  // TODO: can we do SFINAE inside noexcept()?
}

// Answered on 14.06.2023 after all classes: no, noexcept() specifier does not have SFINAE: https://stackoverflow.com/a/33667546/767632
