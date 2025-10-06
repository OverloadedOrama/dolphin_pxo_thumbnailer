#include <KIO/ThumbnailCreator>
#include <KZip>
#include <KPluginFactory>
#include <KArchive>
#include <QImageReader>
#include <QBuffer>

class PixeloramaThumbnailer : public KIO::ThumbnailCreator
{
    Q_OBJECT
public:
    PixeloramaThumbnailer(QObject *parent, const QVariantList &args)
        : KIO::ThumbnailCreator(parent, args) {}

    KIO::ThumbnailResult create(const KIO::ThumbnailRequest &request) override
    {
        const QString path = request.url().toLocalFile();
        qDebug() << "PixeloramaThumbnailer called for" << path;
        KZip zip(path);
        if (!zip.open(QIODevice::ReadOnly)) {
            qWarning() << "Failed to open PXO file as ZIP:" << path;
            return KIO::ThumbnailResult::fail();
        }

        const KArchiveFile *file = zip.directory()->file(QStringLiteral("preview.png"));
        if (!file) {
            qWarning() << "preview.png not found inside PXO:" << path;
            return KIO::ThumbnailResult::fail();
        }

        QImage image;
        image.loadFromData(file->data(), "PNG");
        if (image.isNull()) {
            qWarning() << "Failed to load preview.png as QImage";
            return KIO::ThumbnailResult::fail();
        }

        return KIO::ThumbnailResult::pass(image);
    }
};

K_PLUGIN_FACTORY_WITH_JSON(PixeloramaThumbnailerFactory,
    "pixeloramathumbnailer.json",
    registerPlugin<PixeloramaThumbnailer>();
)

#include "pixeloramathumbnailer.moc"
