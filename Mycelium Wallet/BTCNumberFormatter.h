#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, BTCNumberFormatterUnit) {
    BTCNumberFormatterUnitSatoshi  = 0, // satoshis = 0.00000001 BTC
    BTCNumberFormatterUnitBit      = 2, // bits     = 0.000001 BTC
    BTCNumberFormatterUnitMilliBTC = 5, // mBTC     = 0.001 BTC
    BTCNumberFormatterUnitBTC      = 8, // BTC      = 100 million satoshis
};

typedef NS_ENUM(NSUInteger, BTCNumberFormatterSymbolStyle) {
    BTCNumberFormatterSymbolStyleNone      = 0, // no suffix
    BTCNumberFormatterSymbolStyleCode      = 1, // suffix is BTC, mBTC, Bits or SAT
    BTCNumberFormatterSymbolStyleLowercase = 2, // suffix is btc, mbtc, bits or sat
    BTCNumberFormatterSymbolStyleSymbol    = 3, // suffix is Ƀ, mɃ, ƀ or ṡ
};

extern NSString* const BTCNumberFormatterBitcoinCode;    // XBT
extern NSString* const BTCNumberFormatterSymbolBTC;      // Ƀ
extern NSString* const BTCNumberFormatterSymbolMilliBTC; // mɃ
extern NSString* const BTCNumberFormatterSymbolBit;      // ƀ
extern NSString* const BTCNumberFormatterSymbolSatoshi;  // ṡ

@interface BTCNumberFormatter : NSNumberFormatter

/*!
 * Instantiates and configures number formatter with given unit and suffix style.
 */
- (id) initWithBitcoinUnit:(BTCNumberFormatterUnit)unit;
- (id) initWithBitcoinUnit:(BTCNumberFormatterUnit)unit symbolStyle:(BTCNumberFormatterSymbolStyle)symbolStyle;

/*!
 * Unit size to be displayed (regardless of how it is presented)
 */
@property(nonatomic) BTCNumberFormatterUnit bitcoinUnit;

/*!
 * Style of formatting the units regardless of the unit size.
 */
@property(nonatomic) BTCNumberFormatterSymbolStyle symbolStyle;

/*!
 * Placeholder text for the input field.
 * E.g. "0 000 000.00" for 'bits' and "0.00000000" for 'BTC'.
 */
- (NSString *) placeholderText;

/*!
 * Formats the amount according to units and current formatting style.
 */
- (NSString *) stringFromAmount:(BTCSatoshi)amount;

/*!
 * Returns 0 in case of failure to parse the string.
 * To handle that case, use `-[NSNumberFormatter numberFromString:]`, but keep in mind
 * that NSNumber* will be in specified units, not in satoshis.
 */
- (BTCSatoshi) amountFromString:(NSString *)string;

/*!
 * Converts satoshis to a number in specified units (BTC, mBTC etc).
 */
- (NSNumber*) numberFromSatoshis:(BTCSatoshi)satoshis;

/*!
 * Converts number in specified units (BTC, mBTC etc) to satoshis.
 */
- (BTCSatoshi) satoshisFromNumber:(NSNumber*)number;

@end