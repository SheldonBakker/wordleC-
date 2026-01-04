#pragma once

#include <array>
#include <string_view>

// Official Wordle solution words - common 5-letter English words
// These are the possible answers for the game

namespace EmbeddedWords {

constexpr std::array<std::string_view, 500> SOLUTION_WORDS = {{
    "ABOUT", "ABOVE", "ABUSE", "ACTOR", "ACUTE", "ADMIT", "ADOPT", "ADULT", "AFTER", "AGAIN",
    "AGENT", "AGREE", "AHEAD", "ALARM", "ALBUM", "ALERT", "ALIKE", "ALIVE", "ALLOW", "ALONE",
    "ALONG", "ALTER", "AMONG", "ANGEL", "ANGER", "ANGLE", "ANGRY", "APART", "APPLE", "APPLY",
    "ARENA", "ARGUE", "ARISE", "ARMOR", "ARRAY", "ARROW", "ASIDE", "ASSET", "AVOID", "AWARD",
    "AWARE", "AWFUL", "BACON", "BADGE", "BADLY", "BAKER", "BASIC", "BASIN", "BASIS", "BEACH",
    "BEAST", "BEGAN", "BEGIN", "BEGUN", "BEING", "BELLY", "BELOW", "BENCH", "BERRY", "BIRTH",
    "BLACK", "BLADE", "BLAME", "BLANK", "BLAST", "BLAZE", "BLEED", "BLEND", "BLESS", "BLIND",
    "BLOCK", "BLOOD", "BLOOM", "BLOWN", "BOARD", "BOAST", "BONUS", "BOOTH", "BOUND", "BRAIN",
    "BRAND", "BRASS", "BRAVE", "BREAD", "BREAK", "BREED", "BRICK", "BRIDE", "BRIEF", "BRING",
    "BROAD", "BROKE", "BROOM", "BROWN", "BRUSH", "BUILD", "BUILT", "BUNCH", "BURST", "BUYER",
    "CABIN", "CABLE", "CAMEL", "CANDY", "CARGO", "CARRY", "CATCH", "CAUSE", "CEASE", "CHAIN",
    "CHAIR", "CHALK", "CHAMP", "CHANT", "CHAOS", "CHARM", "CHART", "CHASE", "CHEAP", "CHEAT",
    "CHECK", "CHEEK", "CHEER", "CHESS", "CHEST", "CHICK", "CHIEF", "CHILD", "CHILL", "CHINA",
    "CHORD", "CHOSE", "CHUNK", "CINCH", "CIVIL", "CLAIM", "CLAMP", "CLASH", "CLASP", "CLASS",
    "CLEAN", "CLEAR", "CLERK", "CLICK", "CLIFF", "CLIMB", "CLING", "CLOCK", "CLOSE", "CLOTH",
    "CLOUD", "CLOWN", "COACH", "COAST", "COLOR", "COMET", "COMMA", "CORAL", "COUCH", "COUGH",
    "COULD", "COUNT", "COURT", "COVER", "CRACK", "CRAFT", "CRANE", "CRASH", "CRAWL", "CRAZE",
    "CRAZY", "CREAM", "CREEK", "CREEP", "CRIME", "CRISP", "CROSS", "CROWD", "CROWN", "CRUDE",
    "CRUEL", "CRUSH", "CURLY", "CURRY", "CURSE", "CURVE", "CYCLE", "DAILY", "DAIRY", "DANCE",
    "DEATH", "DECAY", "DECOR", "DELAY", "DELTA", "DEMON", "DENSE", "DEPOT", "DEPTH", "DIARY",
    "DIGIT", "DIRTY", "DISCO", "DITCH", "DIZZY", "DOING", "DOUBT", "DOUGH", "DOZEN", "DRAFT",
    "DRAIN", "DRAMA", "DRANK", "DREAM", "DRESS", "DRIED", "DRIFT", "DRILL", "DRINK", "DRIVE",
    "DROWN", "DRUNK", "DUSTY", "DWARF", "DYING", "EAGER", "EAGLE", "EARLY", "EARTH", "EIGHT",
    "ELBOW", "ELDER", "ELECT", "ELITE", "EMPTY", "ENEMY", "ENJOY", "ENTER", "ENTRY", "EQUAL",
    "ERROR", "ESSAY", "EVENT", "EVERY", "EXACT", "EXILE", "EXIST", "EXTRA", "FAINT", "FAIRY",
    "FAITH", "FALSE", "FANCY", "FARCE", "FAULT", "FAVOR", "FEAST", "FENCE", "FERRY", "FETCH",
    "FEVER", "FIBER", "FIELD", "FIERY", "FIFTH", "FIFTY", "FIGHT", "FILTH", "FINAL", "FIRST",
    "FIXED", "FLAME", "FLASH", "FLEET", "FLESH", "FLICK", "FLING", "FLOAT", "FLOCK", "FLOOD",
    "FLOOR", "FLOUR", "FLOWN", "FLUID", "FLUSH", "FLUTE", "FOCAL", "FOCUS", "FOGGY", "FORCE",
    "FORGE", "FORTH", "FORTY", "FORUM", "FOUND", "FRAME", "FRANK", "FRAUD", "FRESH", "FRIED",
    "FRONT", "FROST", "FRUIT", "FUDGE", "FULLY", "FUNGI", "FUNNY", "FUZZY", "GHOST", "GIANT",
    "GIVEN", "GLAND", "GLASS", "GLEAM", "GLIDE", "GLOBE", "GLOOM", "GLORY", "GLOSS", "GLOVE",
    "GOING", "GRACE", "GRADE", "GRAIN", "GRAND", "GRANT", "GRAPE", "GRAPH", "GRASP", "GRASS",
    "GRAVE", "GRAZE", "GREAT", "GREED", "GREEN", "GREET", "GRIEF", "GRILL", "GRIND", "GROAN",
    "GROOM", "GROSS", "GROUP", "GROVE", "GROWN", "GUARD", "GUESS", "GUEST", "GUIDE", "GUILD",
    "GUILT", "HABIT", "HAIRY", "HANDY", "HAPPY", "HARSH", "HASTE", "HASTY", "HATCH", "HAVEN",
    "HEART", "HEAVY", "HELLO", "HENCE", "HERBS", "HILLY", "HINGE", "HIPPO", "HOBBY", "HOIST",
    "HONEY", "HONOR", "HORSE", "HOTEL", "HOUND", "HOUSE", "HUMAN", "HUMID", "HUMOR", "HURRY",
    "IDEAL", "IMAGE", "IMPLY", "INDEX", "INDIE", "INNER", "INPUT", "INTEL", "INTRO", "IRONY",
    "ISSUE", "IVORY", "JELLY", "JEWEL", "JOINT", "JOKER", "JOLLY", "JUDGE", "JUICE", "JUICY",
    "JUMBO", "JUMPY", "KEBAB", "KHAKI", "KNIFE", "KNOCK", "KNOTS", "KNOWN", "LABEL", "LABOR",
    "LANCE", "LARGE", "LASER", "LATCH", "LATER", "LAUGH", "LAYER", "LEACH", "LEARN", "LEASE",
    "LEAST", "LEAVE", "LEGAL", "LEMON", "LEVEL", "LEVER", "LIGHT", "LIMIT", "LINEN", "LINER",
    "LINKS", "LIPID", "LITRE", "LIVER", "LLAMA", "LOCAL", "LODGE", "LOFTY", "LOGIC", "LOOSE",
    "LORRY", "LOSER", "LOTUS", "LOUD", "LOVER", "LOWER", "LOYAL", "LUCKY", "LUNAR", "LUNCH",
    "LYING", "LYRIC", "MACHO", "MACRO", "MAGIC", "MAJOR", "MAKER", "MANGO", "MANOR", "MAPLE",
    "MARCH", "MARRY", "MARSH", "MATCH", "MAYOR", "MEDAL", "MEDIA", "MELON", "MERCY", "MERGE",
    "MERIT", "MERRY", "MESSY", "METAL", "METER", "MICRO", "MIDST", "MIGHT", "MINOR", "MINUS",
    "MIRTH", "MIXED", "MODEL", "MODEM", "MOIST", "MONEY", "MONTH", "MORAL", "MOTOR", "MOTTO"
}};

// Extended valid guesses - words that are valid inputs but less common as answers
// This is a smaller subset; the full list can be loaded from file
constexpr std::array<std::string_view, 200> EXTRA_VALID_WORDS = {{
    "AAHED", "AALII", "ABASE", "ABASH", "ABATE", "ABBEY", "ABBOT", "ABEAM", "ABELE", "ABHOR",
    "ABIDE", "ABLER", "ABODE", "ABORT", "ABYSS", "ACIDS", "ACINI", "ACMES", "ACNED", "ACORN",
    "ACRES", "ACRID", "ACTED", "ADAGE", "ADDED", "ADDER", "ADDLE", "ADEPT", "ADMIN", "ADMIX",
    "ADOBE", "AEONS", "AERIE", "AFFIX", "AFIRE", "AFOOT", "AFOUL", "AGAIN", "AGATE", "AGAVE",
    "AGENE", "AGING", "AGIOS", "AGISM", "AGIST", "AGLEY", "AGLOW", "AGONE", "AGONY", "AGORA",
    "AGREE", "AHEAD", "AHOLD", "AIDED", "AIDER", "AIDES", "AILED", "AIMED", "AIMER", "AIRED",
    "AIRER", "AISLE", "AITCH", "AJIVA", "ALAMO", "ALARM", "ALBUM", "ALDER", "ALGAE", "ALGID",
    "ALIAS", "ALIBI", "ALIEN", "ALIGN", "ALIKE", "ALINE", "ALLAY", "ALLEY", "ALLOT", "ALLOW",
    "ALLOY", "ALOES", "ALOFT", "ALOHA", "ALONE", "ALONG", "ALOOF", "ALOUD", "ALPHA", "ALTAR",
    "ALTER", "ALTOS", "ALUMS", "AMBER", "AMBIT", "AMBLE", "AMEBA", "AMEND", "AMENT", "AMIDE",
    "AMIGO", "AMINE", "AMINO", "AMISS", "AMITY", "AMOUR", "AMPLE", "AMPLY", "AMUCK", "AMUSE",
    "ANGEL", "ANGER", "ANGLE", "ANGRY", "ANGST", "ANIME", "ANION", "ANISE", "ANKLE", "ANNEX",
    "ANNOY", "ANNUL", "ANODE", "ANTIC", "ANTSY", "ANVIL", "AORTA", "APACE", "APART", "APHID",
    "APIAN", "APING", "APISH", "APNEA", "APPLE", "APPLY", "APRON", "APTLY", "ARBOR", "AREAS",
    "ARENA", "ARGON", "ARGOT", "ARGUE", "ARISE", "ARMOR", "AROMA", "AROSE", "ARRAY", "ARROW",
    "ARSON", "ARTSY", "ASCOT", "ASHEN", "ASHES", "ASIAN", "ASIDE", "ASPEN", "ASPIC", "ASSAY",
    "ASSET", "ATLAS", "ATOLL", "ATOMS", "ATONE", "ATTIC", "AUDIO", "AUDIT", "AUGER", "AUGUR",
    "AURAL", "AVAIL", "AVERT", "AVOID", "AWAIT", "AWAKE", "AWARD", "AWARE", "AWFUL", "AWING",
    "AXIAL", "AXILE", "AXING", "AXIOM", "AXION", "AXLED", "AXLES", "AXONE", "AXONS", "AZURE",
    "BABEL", "BABES", "BACKS", "BACON", "BADGE", "BADLY", "BAGEL", "BAGGY", "BAILS", "BAITS"
}};

} // namespace EmbeddedWords
