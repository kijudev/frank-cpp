#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <variant>
#include <vector>

enum class Op { AND, OR, XOR, IMPL, IF_ONLY, NOT };
using Symbol = uint8_t;

struct Expr;

struct Expr {
    Op                          op;
    std::variant<Symbol, Expr*> left;
    std::variant<Symbol, Expr*> right;

    bool eval(const std::vector<bool>& inputs) {
        bool vl {false}, vr {false};

        switch (op) {
        case Op::AND:
            return eval_part(inputs, left) && eval_part(inputs, right);
        case Op::OR: return eval_part(inputs, left) || eval_part(inputs, right);
        case Op::XOR: return eval_part(inputs, left) ^ eval_part(inputs, right);
        case Op::IMPL:
            return (!eval_part(inputs, left)) || eval_part(inputs, right);
        case Op::IF_ONLY:
            vl = eval_part(inputs, left);
            vr = eval_part(inputs, right);

            return (vl && vr) || ((!vl) && (!vr));
        case Op::NOT: return !eval_part(inputs, left);
        }
    }

private:
    static bool eval_part(
        const std::vector<bool>&          inputs,
        const std::variant<Symbol, Expr*> part) {
        if (part.index() == 0) {
            Symbol s = std::get<Symbol>(part);
            return inputs[s];
        } else {
            return std::get<Expr*>(part)->eval(inputs);
        }
    }
};

int main() {
    Expr              b      = Expr {Op::AND, Symbol(0), Symbol(1)};
    Expr              a      = Expr {Op::OR, Symbol(0), &b};
    std::vector<bool> inputs = {true, false};

    std::cout << a.eval(inputs) << "\n";

    return 0;
}
