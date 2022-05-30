// Destructors cannot be SFINAEd out. C++20: concepts to the rescue!
// Having a destructor makes the difference between TriviallyDestructible types and others.

~Foo() noexcept(?????) {  // TODO: can we do SFINAE inside noexcept()?
}
